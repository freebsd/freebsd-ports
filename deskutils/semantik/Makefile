# New ports collection makefile for:	semantik
# Date created:				2009-08-11
# Whom:					Nick Hibma <nick@anywi.com>
#
# $FreeBSD$
#

PORTNAME=	semantik
PORTVERSION=	0.7.3
PORTREVISION=	1
CATEGORIES=	deskutils kde
MASTER_SITES=	http://${PORTNAME}.googlecode.com/files/ \
		http://freehackers.org/~tnagy/

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	KDE mindmapping tool

LICENSE=	GPLv3

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_KDE4=	kdehier kdelibs kdeprefix
USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=	yes
USE_PYTHON_BUILD=	2.5+
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui linguist svg webkit xml \
		moc_build qmake_build uic_build
MAKE_JOBS_SAFE=	yes
CONFIGURE_ENV=	PATH="${KDE4_PREFIX}/bin:$$PATH" WAF_HOME="${WRKSRC}"
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include
USE_LDCONFIG=	yes

pre-configure:
	${REINPLACE_CMD} -e 's/kde-config/kde4-config/g' \
		-e '/conf.env.CXXFLAGS =/ s|= '"'"'[^'"'"']*|= '"'"'${CXXFLAGS}|' \
		-e 's/-lstr/-lcamlstr/g' \
		-e '/obj.langs/ d' \
		${WRKSRC}/wscript

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./waf configure --prefix=${PREFIX}

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf build ${_MAKE_JOBS}

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf install
	@${STRIP_CMD} ${PREFIX}/bin/${PORTNAME}
.for lang in es fr
	@${LOCALBASE}/bin/msgfmt \
		-o ${KDE4_PREFIX}/share/locale/${lang}/LC_MESSAGES/${PORTNAME}.mo \
		${WRKSRC}/src/po/${lang}.po
.endfor

.include <bsd.port.mk>
