# New ports collection makefile for:	semantik
# Date created:				2009-08-11
# Whom:					Nick Hibma <nick@anywi.com>
#
# $FreeBSD$
#

PORTNAME=	semantik
PORTVERSION=	0.8.0
CATEGORIES=	deskutils kde
MASTER_SITES=	http://${PORTNAME}.googlecode.com/files/ \
		http://freehackers.org/~tnagy/

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	KDE mind mapping tool

LICENSE=	GPLv3

USE_KDE4=	kdehier kdelibs kdeprefix
USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=	yes
USE_PYTHON=	2.5+
USE_QT4=	corelib gui linguist svg webkit xml \
		moc_build qmake_build uic_build
USE_BZIP2=	yes
CONFIGURE_ENV=	PATH="${KDE4_PREFIX}/bin:$$PATH" WAF_HOME="${WRKSRC}"
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

pre-configure:
	${REINPLACE_CMD} -e 's/kde-config/kde4-config/g' \
		-e '/conf.env.CXXFLAGS =/ s|= '"'"'[^'"'"']*|= '"'"'${CXXFLAGS}|' \
		${WRKSRC}/wscript
.if empty(PORT_OPTIONS:MNLS)
	${REINPLACE_CMD} -e '/langs/ d' \
		${WRKSRC}/wscript
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./waf configure --prefix=${PREFIX}

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf build ${_MAKE_JOBS}

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf install
	@${STRIP_CMD} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
