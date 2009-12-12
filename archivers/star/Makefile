# ex:ts=8
# New ports collection makefile for:	star
# Date created:		Thu May  1 20:28:44 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	star
DISTVERSION=	1.5.1
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.berlios.de/pub/star/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Unique standard tape archiver with many enhancements

BUILD_DEPENDS=	${LOCALBASE}/bin/smake:${PORTSDIR}/devel/smake

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_ICONV=	yes

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		star.1 srmt.1 tartest.1
MAN5=		star.5
MLINKS=		star.1 ustar.1 star.5 ustar.5
.else
XMKFLAGS=	XMK_FILE=""
.endif

MAKE_ENV+=	MAKEFLAGS=${MAKEFLAGS}

PORTDOCS=	README README.crash README.mtio README.pattern STARvsGNUTAR \
		README.ACL README.largefiles README.otherbugs \
		README.posix-2001
post-patch:
	@${FIND} ${WRKSRC} -type f -print \
		| ${XARGS} ${REINPLACE_CMD} -e "s@/etc/default@${PREFIX}/etc@g"
	@${MV} ${WRKSRC}/rmt/rmt.1 ${WRKSRC}/rmt/srmt.1

do-build:
	@cd ${WRKSRC} && ${MAKE_ENV} ${LOCALBASE}/bin/smake
	@cd ${WRKSRC}/star && ${MAKE_ENV} ${LOCALBASE}/bin/smake -f Makefile.doc

do-install:
	@cd ${WRKSRC}/star && ${MAKE_ENV} ${LOCALBASE}/bin/smake \
		${INSTALL_TARGET} INS_BASE=${PREFIX} ${XMKFLAGS}
	@cd ${WRKSRC}/rmt && ${MAKE_ENV} ${LOCALBASE}/bin/smake \
		${INSTALL_TARGET} INS_BASE=${PREFIX} ${XMKFLAGS}
	@cd ${WRKSRC}/tartest && ${MAKE_ENV} ${LOCALBASE}/bin/smake \
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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/star/${FILE} ${DOCSDIR}/${FILE}
.endfor
.endif

.include <bsd.port.mk>
