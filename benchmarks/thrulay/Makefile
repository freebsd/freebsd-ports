# New ports collection makefile for:   thrulay
# Date created:        2005-10-19
# Whom:                shalunov
#
# $FreeBSD$

PORTNAME=	thrulay
PORTVERSION=	0.8
CATEGORIES=	benchmarks net ipv6
MASTER_SITES=	http://unc.dl.sourceforge.net/sourceforge/thrulay/ \
		http://internap.dl.sourceforge.net/sourceforge/thrulay/ \
		http://www.internet2.edu/~shalunov/thrulay/

MAINTAINER=	shalunov@shlang.com
COMMENT=	Network capacity tester

MAN1=		thrulay.1
MAN8=		thrulayd.8
MANCOMPRESSED=	no
HAS_CONFIGURE=	yes
USE_GMAKE=	yes

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/thrulayd.sh.sample ${PREFIX}/etc/rc.d/
	@if [ ! -f ${PREFIX}/etc/rc.d/thrulayd.sh ]; then \
		${CP} -p ${PREFIX}/etc/rc.d/thrulayd.sh.sample \
			${PREFIX}/etc/rc.d/thrulayd.sh ; \
	fi

.include <bsd.port.mk>
