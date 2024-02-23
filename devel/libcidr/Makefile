PORTNAME=	libcidr
DISTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.over-yonder.net/~fullermd/projects/${PORTNAME}/ \
		http://distfiles.over-yonder.net/${PORTNAME}/

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	Library to handle manipulating CIDR netblocks
WWW=		https://www.over-yonder.net/~fullermd/projects/libcidr

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		tar:xz
USE_LDCONFIG=	yes
MAKE_ENV+=	CIDR_DOCDIR=${DOCSDIR} CIDR_EXDIR=${EXAMPLESDIR} CIDR_MANDIR=${PREFIX}/share/man

OPTIONS_DEFINE=	DOCS EXAMPLES

DOCS_MAKE_ENV_OFF=	NO_DOCS=yes
EXAMPLES_MAKE_ENV_OFF=	NO_EXAMPLES=yes

post-patch:
	@${REINPLACE_CMD} 's|-g -O2 -pipe||' ${WRKSRC}/src/Makefile.inc

.include <bsd.port.mk>
