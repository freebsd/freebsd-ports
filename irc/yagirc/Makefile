# New ports collection makefile for:   	yagirc
# Version required:			0.65
# Date created:				6 July 1998
# Whom:					mph
#
# $Id: Makefile,v 1.3 1998/08/04 00:52:20 mph Exp $
#

DISTNAME=	yagirc-0.65
CATEGORIES=	net
MASTER_SITES=	http://www.elpaso.net/~spoon/yagirc/

MAINTAINER=	mph@freebsd.org

LIB_DEPENDS=	gtk\\.1\\.\[345\]:${PORTSDIR}/x11-toolkits/gtk \
		Imlib\\.1\\.7:${PORTSDIR}/graphics/imlib

USE_GMAKE=	yes
USE_PERL5=	yes

do-configure:
.if !exists(/usr/lib/libc_r.a)
	@ ${ECHO_MSG} This port requires the multithreading library libc_r.
	@ false
.endif
	@ perl -pe "s,@LOCALBASE@,${LOCALBASE},g; s,@X11BASE@,${X11BASE},g; s,@PREFIX@,${PREFIX},g;" ${FILESDIR}/config.h > ${WRKSRC}/config.h

.include <bsd.port.mk>
