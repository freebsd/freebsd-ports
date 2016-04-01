# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	star
DISTVERSION=	1.5.2
CATEGORIES=	archivers
MASTER_SITES=	http://BSDforge.com/projects/source/srchivers/star/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Unique standard tape archiver with many enhancements

LICENSE=	CDDL GPLv2
LICENSE_COMB=	multi
LICENSE_FILES=	${WRKSRC}/CDDL.Schily.txt

BUILD_DEPENDS=	smake:devel/smake

USES=		gettext iconv tar:bzip2
USE_GCC=	any

.if defined(NO_INSTALL_MANPAGES)
XMKFLAGS=	XMK_FILE=""
.endif

MAKEFLAGS+=	DEFMANBASE=.
MAKE_ENV+=	MAKEFLAGS=${MAKEFLAGS}

PORTDOCS=	README README.crash README.mtio README.pattern STARvsGNUTAR \
		README.ACL README.largefiles README.otherbugs \
		README.posix-2001

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${FIND} ${WRKSRC} -type f -print \
		| ${XARGS} ${REINPLACE_CMD} -e "s@/etc/default@${PREFIX}/etc@g"
	@${MV} ${WRKSRC}/rmt/rmt.1 ${WRKSRC}/rmt/srmt.1

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} smake
	cd ${WRKSRC}/star && ${SETENV} ${MAKE_ENV} smake -f Makefile.doc

do-install:
	cd ${WRKSRC}/star && ${SETENV} ${MAKE_ENV} smake \
		${INSTALL_TARGET} INS_BASE=${STAGEDIR}${PREFIX} ${XMKFLAGS}
	cd ${WRKSRC}/rmt && ${SETENV} ${MAKE_ENV} smake \
		${INSTALL_TARGET} INS_BASE=${STAGEDIR}${PREFIX} ${XMKFLAGS}
	cd ${WRKSRC}/tartest && ${SETENV} ${MAKE_ENV} smake \
		${INSTALL_TARGET} INS_BASE=${STAGEDIR}${PREFIX} ${XMKFLAGS}
# Ugh... cmake doesn't like install-strip
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/star
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/srmt
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/tartest
	${INSTALL_DATA} ${WRKSRC}/star/star.dfl ${STAGEDIR}${PREFIX}/etc/star.sample
	${INSTALL_DATA} ${WRKSRC}/rmt/rmt.dfl ${STAGEDIR}${PREFIX}/etc/rmt.sample

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in ${PORTDOCS}
	(cd ${WRKSRC}/star && ${INSTALL_DATA} ${FILE} ${STAGEDIR}${DOCSDIR}/${FILE})
.endfor
.endif

.include <bsd.port.mk>
