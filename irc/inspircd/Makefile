# New ports collection makefile for:   inspircd
# Date created:        25 August 2006
# Whom:                brain
#
# $FreeBSD$
#

PORTNAME=	inspircd
PORTVERSION=	1.0.6
CATEGORIES=	irc
MASTER_SITES=	http://www.inspircd.org/downloads/ \
		http://www.chatspike.net/downloads/

MAINTAINER=	brain@inspircd.org
COMMENT=	A modular C++ IRC daemon

USE_GCC=	3.2+
USE_GMAKE=	yes

# Configure script is written in perl
USE_PERL5_BUILD=yes

CONFIGURE_ARGS=	-update
HAS_CONFIGURE=	yes

# We're using a nonstandard configure, so these cached
# values must be copied into the ${WRKSRC} directory.
pre-configure:
	@${CP} ${FILESDIR}/config.cache ${WRKSRC}/.config.cache
	@echo 'CC="${CC}"' >> ${WRKSRC}/.config.cache
	@echo 'CONFIG_DIR="${PREFIX}/etc/inspircd"' >> ${WRKSRC}/.config.cache
	@echo 'MODULE_DIR="${PREFIX}/lib/inspircd/modules"' >> ${WRKSRC}/.config.cache
	@echo 'LIBRARY_DIR="${PREFIX}/lib/inspircd"' >> ${WRKSRC}/.config.cache
	@echo 'BASE_DIR="${PREFIX}/inspircd"' >> ${WRKSRC}/.config.cache
	@echo 'BINARY_DIR="${PREFIX}/bin"' >> ${WRKSRC}/.config.cache
	@echo 'ME="${PREFIX}"' >> ${WRKSRC}/.config.cache

# 1.0.6 Makefile forgets to make these directories
# during install. We make these ourselves. This may
# be fixed in a later version of InspIRCd.
pre-su-install:
	@-${MKDIR} ${PREFIX}/inspircd
	@-${MKDIR} ${PREFIX}/lib/inspircd
	@-${MKDIR} ${PREFIX}/lib/inspircd/modules
	@-${MKDIR} ${PREFIX}/etc/inspircd

post-install:
	${STRIP_CMD} ${PREFIX}/lib/inspircd/modules/*.so
	${STRIP_CMD} ${PREFIX}/lib/inspircd/*.so
	${STRIP_CMD} ${PREFIX}/bin/inspircd

.include <bsd.port.mk>
