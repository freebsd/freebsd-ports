# Created by: Bas Kruit <baskruit@bsltwr.dhis.org>
# $FreeBSD$

PORTNAME=	dhisd
PORTVERSION=	5.1
PORTREVISION=	5
CATEGORIES=	dns
MASTER_SITES=	ftp://ftp.dhis.org/pub/dhis/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DHIS server for dynamic updates on the server using specific engines

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		localbase:ldflags

SUB_FILES=	pkg-message

DOCS=		CONTRIBUTORS INSTALL MODULES README
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${CP} ${FILESDIR}/dhisd.sh ${WRKSRC}/dhisd.sh
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e "s^__PREFIX__^${PREFIX}^g" \
		Makefile dhisd.h dhisd.sh ${DOCS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dhisd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/genkeys ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/dhis
	${INSTALL_DATA} ${WRKSRC}/dhis.db.sample ${STAGEDIR}${PREFIX}/etc/dhis/dhis.db.sample
	${INSTALL_DATA} ${WRKSRC}/services.db.sample ${STAGEDIR}${PREFIX}/etc/dhis/services.db.sample
	${INSTALL_SCRIPT} ${WRKSRC}/dhisd.sh ${STAGEDIR}${PREFIX}/etc/rc.d/dhisd.sh

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOCS}
	cd ${WRKSRC} && ${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${FILESDIR}/INSTALL.bsd ${STAGEDIR}${DOCSDIR}

post-install-DOCS-on:
	@${REINPLACE_CMD} -e 's|^__DOCS__||' ${PKGMESSAGE}

post-install-DOCS-off:
	@${REINPLACE_CMD} -e '/^__DOCS__/ d' ${PKGMESSAGE}

.include <bsd.port.mk>
