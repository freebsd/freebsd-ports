# New ports collection makefile for:	sybase-openclient
# Date created:			Jul 25, 2002
# Whom:				mi
#
# $FreeBSD$
#

PORTNAME=	sybase-ocsd
PORTVERSION=	10.0.4.6
CATEGORIES=	databases
MASTER_SITES=	http://linux.sybase.com/REL11033/ \
		http://virtual-estates.net/~mi/port-stuff/
DISTFILES=	${PORTNAME}-${PORTVERSION:R}-FreeBSD-${PORTVERSION:E}.i386.tgz \
		LICENSE ${RESTRICTED_FILES}
DIST_SUBDIR=	sybase
EXTRACT_ONLY=

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Headers and static libraries of Sybase OpenClient

NO_BUILD=	no sources :-\
WRKSRC=		${WRKDIR}/sybase
ONLY_FOR_ARCHS=	i386
NO_PACKAGE=	Packaging is pointless, the port does not build anything

# The file below contains the locale data files missing from the official
# distribution. Sybase noticed the mistake in
#	http://www.sybase.com/detail/1,6904,2894,00.html
# but the only reasonable workaround suggested there points to a broken
# link. This file is just a subset of a much bigger
#	http://linux.sybase.com/REL11033/sybase-ase-11.0.3.3-FreeBSD-6.i386.tgz
# which, despite its name, contains only Linux binaries and kernel patches.

# I follow the spirit of the license by making the locale file available
# unaltered, but don't want FreeBSD to appear to disrespect the letter.
# A comment from Sybase would be most welcome as well as the newer version
# of the binaries for all of the FreeBSD platforms.
RESTRICTED_FILES=sybase-11.0.3.3-locale.tar.bz2

do-install:
	${TAR} -xpzf ${_DISTDIR}/${DISTFILES:M*.tgz} -C ${PREFIX} \
		sybase/include sybase/lib sybase/devlib
	${TAR} -xpyf ${_DISTDIR}/${DISTFILES:M*locale*} -C ${PREFIX}/sybase
	${INSTALL_DATA} ${FILESDIR}/interfaces.sample ${PREFIX}/sybase/
	-@${SED} 's|PREFIX|${PREFIX}|g' < pkg-message

.include <bsd.port.mk>
