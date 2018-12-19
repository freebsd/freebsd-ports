# Created by: Devon H. O'Dell <devon.odell@coyotepoint.com>
# $FreeBSD$

PORTNAME=	ser2net
PORTVERSION=	3.5.1
CATEGORIES=	comms net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Allows to access serial ports over IP

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool
USE_RC_SUBR=	${PORTNAME}

GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog NEWS README
PLIST_FILES=	sbin/${PORTNAME} etc/${PORTNAME}.conf.sample \
		man/man8/${PORTNAME}.8.gz

OPTIONS_DEFINE=	DOCS

post-patch:
.for i in ${PORTNAME}.c ${PORTNAME}.8
	@${REINPLACE_CMD} -e \
		's!/etc!${PREFIX}/etc!g' ${WRKSRC}/${i}
.endfor
.for i in ${PORTNAME}.conf
	@${REINPLACE_CMD} -e \
		's!ttyS!cuad!g' ${WRKSRC}/${i}
.endfor
	@${REINPLACE_CMD} -e '/#include <values\.h>/d' \
		${WRKSRC}/readconfig.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 \
		${STAGEDIR}${MAN8PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S!^!${WRKSRC}/!} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
