# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	star
DISTVERSION=	1.5.2
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.berlios.de/pub/star/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unique standard tape archiver with many enhancements

BUILD_DEPENDS=	smake:${PORTSDIR}/devel/smake

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_ICONV=	yes

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		scpio.1 spax.1 srmt.1 star.1 suntar.1 tartest.1
MAN5=		star.5
MLINKS=		star.1 ustar.1 star.5 ustar.5
.else
XMKFLAGS=	XMK_FILE=""
.endif

MAKEFLAGS+=	MANBASE=
MAKE_ENV+=	MAKEFLAGS=${MAKEFLAGS}

PORTDOCS=	README README.crash README.mtio README.pattern STARvsGNUTAR \
		README.ACL README.largefiles README.otherbugs \
		README.posix-2001

.include <bsd.port.options.mk>

post-patch:
	@${FIND} ${WRKSRC} -type f -print \
		| ${XARGS} ${REINPLACE_CMD} -e "s@/etc/default@${PREFIX}/etc@g"
	@${MV} ${WRKSRC}/rmt/rmt.1 ${WRKSRC}/rmt/srmt.1

do-build:
	cd ${WRKSRC} && ${MAKE_ENV} smake
	cd ${WRKSRC}/star && ${MAKE_ENV} smake -f Makefile.doc

do-install:
	cd ${WRKSRC}/star && ${MAKE_ENV} smake \
		${INSTALL_TARGET} INS_BASE=${PREFIX} ${XMKFLAGS}
	cd ${WRKSRC}/rmt && ${MAKE_ENV} smake \
		${INSTALL_TARGET} INS_BASE=${PREFIX} ${XMKFLAGS}
	cd ${WRKSRC}/tartest && ${MAKE_ENV} smake \
		${INSTALL_TARGET} INS_BASE=${PREFIX} ${XMKFLAGS}
	@${STRIP_CMD} ${PREFIX}/bin/star
	@${STRIP_CMD} ${PREFIX}/sbin/srmt
	@${STRIP_CMD} ${PREFIX}/bin/tartest
	@${INSTALL_DATA} ${WRKSRC}/star/star.dfl ${PREFIX}/etc/star.sample
	@if [ ! -f ${PREFIX}/etc/star ]; then \
		${CP} -p ${PREFIX}/etc/star.sample ${PREFIX}/etc/star; \
	fi
	@${INSTALL_DATA} ${WRKSRC}/rmt/rmt.dfl ${PREFIX}/etc/rmt.sample
	@if [ ! -f ${PREFIX}/etc/rmt ]; then \
		${CP} -p ${PREFIX}/etc/rmt.sample ${PREFIX}/etc/rmt; \
	fi

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/star/${FILE} ${DOCSDIR}/${FILE}
.endfor
.endif

.include <bsd.port.mk>
