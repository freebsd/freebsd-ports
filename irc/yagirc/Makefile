# New ports collection makefile for:   	yagirc
# Version required:			0.64
# Date created:				6 July 1998
# Whom:					mph
#
# $Id: Makefile,v 1.1.1.1 1998/07/07 20:35:57 mph Exp $
#

DISTNAME=	yagirc-0.64
CATEGORIES=	net
MASTER_SITES=	http://www.sicom.fi/~ikioma/

MAINTAINER=	mph@freebsd.org

LIB_DEPENDS=	gtk\\.1\\.5:${PORTSDIR}/x11/gtk

USE_GMAKE=	yes
USE_PERL5=	yes

do-configure:
	@ perl -pe "s,@LOCALBASE@,${LOCALBASE},g; s,@X11BASE@,${X11BASE},g; s,@PREFIX@,${PREFIX},g;" ${FILESDIR}/config.h > ${WRKSRC}/config.h

.include <bsd.port.mk>
