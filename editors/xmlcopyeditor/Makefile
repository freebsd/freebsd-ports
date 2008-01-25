# New ports collection makefile for:   	xmlcopyeditor
# Date created:        			6 December 2007
# Whom:                			José García Juanino <jjuanino@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	xmlcopyeditor
PORTVERSION=	1.1.0.6
CATEGORIES=	editors
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=xml-copy-editor

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Fast validating XML editor

USE_WX=		2.8+
WX_COMPS=	wx contrib
WX_CONF_ARGS=	absolute
WX_UNICODE=	yes
USE_GETTEXT=	yes
USE_DOS2UNIX=	src/rulesets/ruleset.css \
		src/rulesets/ruleset.xsd \
		src/rulesets/Contractions.xml \
		src/aspellpaths.h \
		src/po/sk/backup/sk.po \
		src/po/sk/sk.po \
		src/po/fr/messages.po \
		src/po/sv/messages.po \
		src/po/translate.txt \
		src/po/de/messages.po \
		src/po/en_us/messages.po \
		src/help/xmlcopyeditor.hhp \
		src/help/html/generic.css \
		src/rng/docbook.rnc \
		src/rng/tei_all.rnc \
		src/rng/tei_minimal.rnc \
		src/rng/docbookxi.rnc \
		src/templates/DTD.dtd \
		src/filters/WordprocessingML.xml

BUILD_DEPENDS+=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost
LIB_DEPENDS+=	xerces-c.27:${PORTSDIR}/textproc/xerces-c2 \
		xslt.2:${PORTSDIR}/textproc/libxslt \
		aspell.16:${PORTSDIR}/textproc/aspell \
		pcre.0:${PORTSDIR}/devel/pcre

USE_AUTOTOOLS=	autoconf:261 automake:19

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include \
			-I${LOCALBASE}/include/libxml2 ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.include <bsd.port.mk>
