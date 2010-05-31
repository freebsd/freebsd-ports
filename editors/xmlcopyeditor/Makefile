# New ports collection makefile for:   	xmlcopyeditor
# Date created:        			6 December 2007
# Whom:                			José García Juanino <jjuanino@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	xmlcopyeditor
PORTVERSION=	1.2.0.4
PORTREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	SF/xml-copy-editor/${PORTNAME}-linux/${PORTVERSION}

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Fast validating XML editor

USE_WX=		2.8+
WX_COMPS=	wx contrib
WX_CONF_ARGS=	absolute
WX_UNICODE=	yes
USE_GETTEXT=	yes
USE_DOS2UNIX=	src/templates/DTD.dtd \
		src/help/html/generic.css \
		src/help/xmlcopyeditor.hhp \
		src/rulesets/ruleset.css \
		src/rng/tei_all.rnc \
		src/rng/docbook.rnc \
		src/rng/tei_minimal.rnc \
		src/rng/docbookxi.rnc \
		src/po/en_us/messages.po

BUILD_DEPENDS+=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS+=	xerces-c.27:${PORTSDIR}/textproc/xerces-c2 \
		xslt.2:${PORTSDIR}/textproc/libxslt \
		aspell.16:${PORTSDIR}/textproc/aspell \
		pcre.0:${PORTSDIR}/devel/pcre \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		expat.6:${PORTSDIR}/textproc/expat2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

# workaround for automake (it needs config.rpath)
post-extract:
	${TOUCH} ${WRKSRC}/config.rpath

# iconv.m4 is located in ${LOCALBASE}/share/aclocal
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
USE_AUTOTOOLS=	aclocal:110 autoconf:262 automake:110 libtool:22

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include \
			-I${LOCALBASE}/include/libxml2 ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.include <bsd.port.mk>
