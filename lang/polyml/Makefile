# New ports collection makefile for:   polyml
# Date created:        09 July 2005
# Whom:                Timothy Bourke <timbob@bigpond.com>
#
# $FreeBSD$
#

PORTNAME=	polyml
PORTVERSION=	4.1.3
CATEGORIES=	lang
DISTFILES=	polyml-driver-4.1.3.tar.gz \
		polyml-mlsource-4.1.3.tar.gz \
		polyml-basis-4.1.3.tar.gz \
		polyml-4.1.3.i386.tar.gz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	timbob@bigpond.com
COMMENT=	Fast open-source implementation of Standard ML

WRKSRC=		${WRKDIR}/driver
ONLY_FOR_ARCHS=	i386
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	${PREFIX}

SUB_FILES=	poly pkg-message
PLIST_FILES=	bin/poly \
		lib/polyml/poly \
		lib/polyml/LICENCE \
		lib/polyml/ML_dbase \
		lib/polyml/DB413Release
PLIST_DIRS=	lib/polyml

RESTRICTED=	Downloading implies agreement to the licence.

NO_INSTALL_MANPAGES=yes

.include <bsd.port.pre.mk>
TO_BE_FETCHED=

.for f in ${DISTFILES}
.if ! exists (${DISTDIR}/${DIST_SUBDIR}/${f})
TO_BE_FETCHED+=		${f}
.endif
.endfor

do-fetch:
.if ${TO_BE_FETCHED} != ""
ECHO_MSG=/usr/bin/printf
IGNORE=	:\n\n\
------------------------------------------------------------------\n\
Downloading this software implies acceptance of the licence\n\
agreement, which may be found at: http://www.polyml.org/Get.html\n\
\n\
Please download the following files into ${DISTDIR}/${DIST_SUBDIR}\n\
\n
.for f in ${TO_BE_FETCHED}
IGNORE+=	${f}\n
.endfor
IGNORE+=------------------------------------------------------------------\n\n
.endif

post-build:
	(cd ${WRKDIR}/mlsource/MLCompiler/CodeTree; ${LN} -fs CodeCons.i386 CodeCons)
	(cd ${WRKDIR}; ./driver/poly ML_dbase < mlsource/BuildAll.sml)

post-install:
	@${INSTALL_DATA} ${WRKDIR}/DB413Release ${PREFIX}/lib/polyml/
	@${INSTALL_SCRIPT} ${WRKDIR}/poly ${PREFIX}/bin/poly
	(cd ${PREFIX}/lib/polyml; ${LN} -fs ./DB413Release ML_dbase)
	@${CAT} ${PKGMESSAGE}
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

install-user:
.if !exists (${LOCALBASE}/lib/polyml/ML_dbase)
	@${ECHO_CMD}
	@${ECHO_CMD} "You need to install the Poly/ML port first!"
	@${ECHO_CMD}
.elif exists (${HOME}/.polyml/ML_dbase)
	@${ECHO_CMD}
	@${ECHO_CMD} "User copy of database already exists. Aborting!"
	@${ECHO_CMD}
.else
	${MKDIR} ${HOME}/.polyml
	${CP}	${LOCALBASE}/lib/polyml/ML_dbase ${HOME}/.polyml
	${CHMOD} 0600 ${HOME}/.polyml/ML_dbase
.endif

.include <bsd.port.post.mk>
