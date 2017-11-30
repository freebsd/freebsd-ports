# Created by: Amar Takhar <verm@drunkmonk.net>
# $FreeBSD$

PORTNAME=	fastresolve
PORTVERSION=	2.10
PORTREVISION=	6
CATEGORIES=	dns
MASTER_SITES=	http://BSDforge.com/projects/source/dns/fastresolve/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Programs to get DNS and domain ownership information from web logs

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libadns.so:dns/adns
RUN_DEPENDS=	p5-BerkeleyDB>=0:databases/p5-BerkeleyDB

USES=		bdb localbase:ldflags perl5 tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PERL=${PERL} \
		djm_cv_lib_db_Dbopen=yes

LDFLAGS+=	-L${BDB_LIB_DIR}
CXXFLAGS+=	-I${BDB_INCLUDE_DIR}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's/-ldb"/-l${BDB_LIB_CXX_NAME}"/' \
		${WRKSRC}/configure

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS COPYING ChangeLog INSTALL NEWS README
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/TODO ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/timings ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
