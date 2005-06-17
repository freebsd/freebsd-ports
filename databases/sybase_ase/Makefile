# New ports collection makefile for: sybase-ase
# Date created:        8 March 2003
# Whom:                Alex Kiesel
#
# $FreeBSD$
#

PORTNAME=       sybase_ase
PORTVERSION=    11.0.3.3
CATEGORIES=     databases
MASTER_SITES=   http://download.sybase.com/pub/ase1103_linux/
DISTNAME=       ${PORTNAME:S/_/-/}-${PORTVERSION:S/./_/g}-FreeBSD-6_i386
EXTRACT_SUFX=   .tgz

MAINTAINER=     kiesel@schlund.de
COMMENT=        Sybase ASE RDBM System 11

RESTRICTED=     "Please see the license"
NO_BUILD=       "This is a precompiled package"
ONLY_FOR_ARCHS= i386
NO_PACKAGE=     "Packaging is pointless, the port does not build anything"
NO_INSTALL_MANPAGES= yes
PKGDEINSTALL=	${PKGDIR}/pkg-install

USE_LINUX=	yes

pre-install:
	@${ECHO_MSG} "---> Creating sybase user and group"
	@PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	${MKDIR} ${PREFIX}/sybase-ase
	${TAR} -xzpf ${_DISTDIR}${DISTFILES} -C ${PREFIX}/sybase-ase
	${MV} ${PREFIX}/sybase-ase/sybase/* ${PREFIX}/sybase-ase/
	${CHOWN} -R sybase:sybase ${PREFIX}/sybase-ase
	${INSTALL_SCRIPT} ${FILESDIR}/sybase.sh.sample ${PREFIX}/etc/rc.d/
	@${ECHO_MSG} "Sybase ASE ${PORTVERSION} has been successfully installed."
	@${ECHO_MSG} "A sample startup script has been copied to"
	@${ECHO_MSG} "${PREFIX}/etc/rc.d/sybase.sh.sample"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You must now configure your sybase. To do so, su to 'sybase'"
	@${ECHO_MSG} "and run ./install/sybinit"

.include <bsd.port.mk>
