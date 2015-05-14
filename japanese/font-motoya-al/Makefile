# $FreeBSD$

PORTNAME=	font-motoya-al
PORTVERSION=	0.0.20100921
PORTREVISION=	3
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	LOCAL/hrs
DISTNAME=	motoya-al-fonts-${PORTVERSION:S,^0.0.,,}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Free Japanese fonts by MOTOYA

USES=	fonts tar:bzip2
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
PORTDOCS=	newsrelease20100921.pdf

FONTNAME=	TTF
OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${STAGEDIR}${FONTSDIR} && ${LN} -s -f \
	    ../../../${DATADIR_REL}/MTL*.ttf .
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d
	${INSTALL_DATA} ${FILESDIR}/20-unhint-motoya-al.conf \
	    ${FILESDIR}/62-fonts-motoya-al.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-motoya-al.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/20-unhint-motoya-al.conf
	${LN} -s -f ../conf.avail/62-fonts-motoya-al.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/62-fonts-motoya-al.conf
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
