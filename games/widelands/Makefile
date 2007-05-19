# Ports collection makefile for:        widelands
# Date created:                         8 April 2007
# Whom:                                 Bartosz Fabianowski <freebsd@chillt.de>
#
# $FreeBSD$
#

PORTNAME=	widelands
DISTVERSION=	build10
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${DISTVERSION}-source

MAINTAINER=	freebsd@chillt.de
COMMENT=	Realtime strategy game inspired by Settlers II

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/widelands
PLIST=		${WRKDIR}/pkg-plist
USE_BZIP2=	yes
USE_PYTHON_BUILD=	2.4+
USE_GETTEXT=	yes
USE_SDL=	mixer image net ttf

SCONS_ARGS=	CXXFLAGS="${CXXFLAGS}" LINKFLAGS="${LDFLAGS}" \
		CPPPATH=${LOCALBASE}/include LIBPATH=${LOCALBASE}/lib \
		CC="${CC}" CXX="${CXX}" \
		install_prefix=${PREFIX} bindir=bin datadir=share/widelands

post-patch:
	@${REINPLACE_CMD} -e 's|options=opts|options=opts, **dict((k, v.split()) for k, v in ARGUMENTS.iteritems())|' \
		${WRKSRC}/SConstruct
	@${REINPLACE_CMD} -e 's|, True||' ${WRKSRC}/worlds/SConscript
	@${RM} -f ${WRKSRC}/worlds/SConscript.bak

do-build:
	@cd ${WRKSRC} && \
		(cd utils && ${TAR} xf scons-local-0.96.1.tar.gz) && \
		${PYTHON_CMD} utils/scons.py ${SCONS_ARGS}

pre-install:
	@${RM} -f ${PLIST}
	@${ECHO_CMD} bin/widelands > ${PLIST}
	@for f in COPYING CREDITS ChangeLog README developers editor_readme ; do \
		${ECHO_CMD} %%DATADIR%%/doc/$$f >> ${PLIST} ; \
	done
	@cd ${WRKSRC} && for d in campaigns maps ; do \
		${LS} -1d $$d/*.wmf | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} ; \
	done
	@cd ${WRKSRC} && for d in fonts game_server music pics sound tribes worlds ; do \
		${FIND} $$d -type f \! -name SConscript | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} ; \
	done
	@for d in doc campaigns maps ; do \
		${ECHO_CMD} "@dirrm %%DATADIR%%/$$d" >> ${PLIST} ; \
	done
	@cd ${WRKSRC} && for d in fonts game_server music pics sound tribes worlds ; do \
		${FIND} $$d -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm %%DATADIR%%/|' >> ${PLIST} ; \
	done
	@${ECHO_CMD} "@dirrm %%DATADIR%%" >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${PYTHON_CMD} utils/scons.py ${SCONS_ARGS} install

.include <bsd.port.mk>
