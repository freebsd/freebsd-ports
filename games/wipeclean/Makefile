PORTNAME=	wipeclean
PORTVERSION=	1.1.2
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	CLI tool to wipe away your error messages in style
WWW=		https://github.com/JeanJouliaCode/wipeClean

LICENSE=	ISCL

USES=		dos2unix nodejs:run tar:xz

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${LN} -fs ${DATADIR}/node_modules/wipeclean/index.js \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

dist: clean
	@npm install --prefix ${WRKSRC} ${PORTNAME}@${PORTVERSION}
	@${TAR} -C ${WRKDIR} -cvJpf ${DISTDIR}/${DISTFILES} ${DISTNAME}

.include <bsd.port.mk>
