PORTNAME=	${MTANAME:tl}
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	games linux
MASTER_SITES=	http://files.gonnaplay.com/201/:main \
		http://www.trancevibez.com/mta/:both \
		http://files.gonnaplay.com/20104/:patch
DISTFILES=	${MTANAME}0_5-linux.tar.gz:main,both ${MTANAME}0_5-linux-patch1.tar.gz:patch,both
DIST_SUBDIR=	mta

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi Theft Auto: Vice City and GTA3 dedicated server

LICENSE=	MTA
LICENSE_NAME=	MTA v0.5 LICENSE AGREEMENT
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror

USES=		linux
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USE_RC_SUBR=	mtad
MTANAME=	MTAServer
PORTDOCS=	CHANGELOG LICENSE README
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

post-extract:
	@${MV} ${WRKSRC}/${MTANAME} ${WRKSRC}/${PORTNAME}
	@${CHMOD} 600 ${WRKSRC}/${PORTNAME}.conf

post-patch:
	@${REINPLACE_CMD} "s|banned.lst|${ETCDIR}/&|" ${WRKSRC}/${PORTNAME}.conf

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${BRANDELF} -t Linux ${WRKSRC}/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf \
		${STAGEDIR}/${ETCDIR}/${PORTNAME}.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
