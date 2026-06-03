PORTNAME=	ser2net
PORTVERSION=	4.6.5
CATEGORIES=	comms net
MASTER_SITES=	https://github.com/cminyard/${PORTNAME}/releases/download/v${PORTVERSION}/

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Allows to access serial ports over IP
WWW=		https://www.sourceforge.net/projects/ser2net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgensio.so:comms/gensio \
		libyaml.so:textproc/libyaml

USES=		libtool
USE_RC_SUBR=	${PORTNAME}

GNU_CONFIGURE=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS

post-patch:
.for i in ${PORTNAME}.c ${PORTNAME}.8
	@${REINPLACE_CMD} -e \
		's!/etc!${PREFIX}/etc!g' ${WRKSRC}/${i}
.endfor
.for i in ${PORTNAME}.yaml
	@${REINPLACE_CMD} -e \
		's!ttyS!cuad!g' ${WRKSRC}/${i}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 \
		${STAGEDIR}${PREFIX}/share/man/man8
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}/ && \
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.yaml \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}/${PORTNAME}.yaml.sample
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.yaml.5 \
		${STAGEDIR}${PREFIX}/share/man/man5

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S!^!${WRKSRC}/!} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
