# New ports collection makefile for:   inspircd
# Date created:        25 August 2006
# Whom:                brain
#
# $FreeBSD$
#

PORTNAME=	inspircd
PORTVERSION=	1.1.8
CATEGORIES=	irc
MASTER_SITES=	http://www.inspircd.org/downloads/ \
		http://www.chatspike.net/downloads/
DISTNAME=	InspIRCd-${PORTVERSION}

MAINTAINER=	brain@inspircd.org
COMMENT=	A modular C++ IRC daemon

WRKSRC=	${WRKDIR}/inspircd
USE_GMAKE=	yes
USE_BZIP2=	yes

# Configure script is written in perl
USE_PERL5_BUILD=yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cc=${CXX} --config-dir=${PREFIX}/etc/inspircd \
		--module-dir=${PREFIX}/lib/inspircd/modules \
		--library-dir=${PREFIX}/lib/inspircd \
		--prefix=${PREFIX}/inspircd --binary-dir=${PREFIX}/bin \
		--enable-remote-ipv6 --disable-interactive

# 1.0.6 Makefile forgets to make these directories
# during install. We make these ourselves. This may
# be fixed in a later version of InspIRCd.
pre-install:
	@${INSTALL} -d ${PREFIX}/inspircd/
	@${INSTALL} -d ${PREFIX}/lib/inspircd/
	@${INSTALL} -d ${PREFIX}/lib/inspircd/modules/
	@${INSTALL} -d ${PREFIX}/etc/inspircd/

post-install:
	@${STRIP_CMD} ${PREFIX}/lib/inspircd/modules/*.so
	@${STRIP_CMD} ${PREFIX}/lib/inspircd/*.so
	@${STRIP_CMD} ${PREFIX}/bin/inspircd
	@${CHMOD} -R a+rX ${PREFIX}/bin/inspircd ${PREFIX}/inspircd/ ${PREFIX}/lib/inspircd/

.include <bsd.port.mk>
