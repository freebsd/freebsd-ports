# New ports collection makefile for:	libsbml
# Date created:			29 May, 2009
# Whom:				Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libsbml
PORTVERSION=	4.0.1
CATEGORIES=	biology devel
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	sbml/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	wen@FreeBSD.org
COMMENT=	An API Library for Working with SBML File

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

OPTIONS=	PYTHON "Support for Python" off \
		RUBY "Support for Ruby" off

USE_GMAKE=	yes
USE_ZIP=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>
.if defined(WITH_PYTHON)
.include "../../Mk/bsd.python.mk"
BUILD_DEPENDS+=		${LOCALBASE}/bin/python:${PORTSDIR}/lang/python
CONFIGURE_ARGS+=	--with-python
PLIST_SUB+=		WITH_PYTHON="" \
			SBML_EGGINFO=${PORTNAME}-${PORTVERSION}-${PYTHON_VERSION:S/thon//}.egg-info
.else
PLIST_SUB+=		WITH_PYTHON="@comment "
.endif

.if defined(WITH_RUBY)
.include "../../Mk/bsd.ruby.mk"
BUILD_DEPENDS+=		${LOCALBASE}/bin/ruby:${PORTSDIR}/lang/ruby18
CONFIGURE_ARGS+=	--with-ruby
PLIST_SUB+=		WITH_RUBY=""
.else
PLIST_SUB+=		WITH_RUBY="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's#%%PREFIX%%#${PREFIX}#' \
		${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples \
		&& ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/\{} \; \
		&& ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${EXAMPLESDIR}/\{} \;
.endif
.include <bsd.port.post.mk>
