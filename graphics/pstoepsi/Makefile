# Created by: Mita Yoshio <mita@jp.FreeBSD.org>
# $FreeBSD$

PORTNAME=	pstoepsi
PORTVERSION=	20020711
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	ftp://bourbon.usc.edu/pub/tgif/tools/pstoepsi/
DISTFILES=	pstoepsi README.this-site
DIST_SUBDIR=	pstoepsi
EXTRACT_ONLY=	#empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wiliam Chia-Wei Cheng's yet another PS to EPSI converter

RUN_DEPENDS=	pbmtoepsi:${PORTSDIR}/graphics/netpbm

USES=		ghostscript:run
NO_WRKSUBDIR=	yes

pre-patch:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/pstoepsi ${WRKSRC}/pstoepsi.prefix
	${CP} ${DISTDIR}/${DIST_SUBDIR}/README.this-site ${WRKSRC}

do-build:
	${SED} -e "s+%%PREFIX%%+${PREFIX}+g" ${WRKSRC}/pstoepsi.prefix > \
						${WRKSRC}/pstoepsi
	${GZIP_CMD} ${WRKSRC}/README.this-site

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pstoepsi ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.this-site.gz ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
