PORTNAME=	hetzner_ddns
DISTVERSION=	0.2.2
CATEGORIES=	dns

MAINTAINER=	filip@parag.rs
COMMENT=	Hetzner Dynamic DNS Daemon

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	jq:textproc/jq \
		curl:ftp/curl

NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	filiparag

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz \
		"@sample etc/${PORTNAME}.conf.sample"

USE_RC_SUBR=	${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.sh \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1.man \
		${STAGEDIR}${MANPREFIX}/share/man/man1/${PORTNAME}.1
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
