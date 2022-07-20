PORTNAME=	weex
PORTVERSION=	2.8.4.1
CATEGORIES=	ftp
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Non-interactive FTP client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/COPYING

USES=		autoreconf cpe gettext-tools gmake ssl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cafile=${LOCALBASE}/share/certs/ca-root-nss.crt
CPPFLAGS+=	-I${OPENSSLINC}
LIBS+=		-L${OPENSSLLIB}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	EXAMPLES NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${RM} -r ${WRKSRC}/intl

pre-configure:
	${CP} ${LOCALBASE}/share/gettext/po/Makevars.template \
		${WRKSRC}/po/Makevars

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/sample.weexrc ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
