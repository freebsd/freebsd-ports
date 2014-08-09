# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	libsbml
PORTVERSION=	5.10.0
CATEGORIES=	biology devel
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	sbml/${PORTNAME}/${PORTVERSION}/stable
DISTNAME=	libSBML-${PORTVERSION}-core-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	API Library for Working with SBML File

LICENSE=	LGPL21

LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2

OPTIONS_DEFINE=	PYTHON RUBY EXAMPLES

USES=		gmake libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=		yes
BUILD_DEPENDS+=		${LOCALBASE}/bin/python:${PORTSDIR}/lang/python
CONFIGURE_ARGS+=	--with-python
PLIST_SUB+=		WITH_PYTHON="" \
			SBML_EGGINFO=${PORTNAME}-${PORTVERSION}-${PYTHON_VERSION:S/thon//}.egg-info
.else
PLIST_SUB+=		WITH_PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MRUBY}
USE_RUBY=		yes
BUILD_DEPENDS+=		${LOCALBASE}/bin/ruby:${PORTSDIR}/lang/ruby19
CONFIGURE_ARGS+=	--with-ruby
PLIST_SUB+=		WITH_RUBY=""
.else
PLIST_SUB+=		WITH_RUBY="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's#%%PREFIX%%#${STAGEDIR}${PREFIX}#' \
		${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples \
		&& ${FIND} . -type f -name "._Makefile.in" -exec ${RM} -f {} \; \
		&& ${FIND} . -type d -exec ${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/\{} \; \
		&& ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${STAGEDIR}${EXAMPLESDIR}/\{} \;
.endif
.include <bsd.port.mk>
