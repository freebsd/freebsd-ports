# New ports collection makefile for:   polyml
# Date created:        09 July 2005
# Whom:                Timothy Bourke <timbob@bigpond.com>
#
# $FreeBSD$
#

PORTNAME=	polyml
PORTVERSION=	4.2.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	driver.420.tar.gz \
		mlsource.420.tar.gz \
		basis.420.tar.gz \
		DB420.i386.unix.gz
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	driver.420.tar.gz \
		mlsource.420.tar.gz \
		basis.420.tar.gz

MAINTAINER=	timbob@bigpond.com
COMMENT=	Fast open-source implementation of Standard ML

WRKSRC=		${WRKDIR}/driver

ONLY_FOR_ARCHS=	i386

USE_GCC=	3.2+
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	${PREFIX}

SUB_FILES=	poly
PLIST_FILES=	bin/poly \
		lib/polyml/poly \
		lib/polyml/COPYING \
		lib/polyml/ML_dbase \
		lib/polyml/DB420.i386.unix
PLIST_DIRS=	lib/polyml

NO_INSTALL_MANPAGES=yes

post-extract:
	@${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/DB420.i386.unix.gz \
		> ${WRKDIR}/DB420.i386.unix

post-patch:
	@${REINPLACE_CMD} -e "s|gcc|${CC}|g" ${WRKSRC}/configure

post-build:
	(cd ${WRKDIR}/mlsource/MLCompiler/CodeTree; ${LN} -fs CodeCons.i386 CodeCons)
	(cd ${WRKDIR}; ./driver/poly DB420.i386.unix < mlsource/BuildAll.sml)

post-install:
	${INSTALL_DATA} ${WRKDIR}/DB420.i386.unix ${PREFIX}/lib/polyml/
	${INSTALL_SCRIPT} ${WRKDIR}/poly ${PREFIX}/bin/poly
	@(cd ${PREFIX}/lib/polyml; ${LN} -fs ./DB420.i386.unix ML_dbase)
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
	@${MKDIR} ${HOME}/.polyml
	@${CP} ${LOCALBASE}/lib/polyml/ML_dbase ${HOME}/.polyml
	@${CHMOD} 0600 ${HOME}/.polyml/ML_dbase
.endif

.include <bsd.port.mk>
