# New ports collection makefile for:    xconq
# Version required:     7.2.1
# Date created:         2 Jun 1998
# Whom:                 Don Croyle <croyle@gelemna.ft-wayne.in.us>
#
# $Id$
#

DISTNAME=	xconq-7.2.1
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.cygnus.com/pub/xconq/

MAINTAINER=	croyle@gelemna.ft-wayne.in.us

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xpm

USE_X11=	yes

MAN6=		xconq.6 cconq.6

pre-configure:
	${CP} ${FILESDIR}/mh-freebsd ${WRKSRC}/config/

post-build:
	cd ${WRKSRC}/doc && make info

post-install:
.for file in xconq cconq
	strip ${PREFIX}/bin/${file}
.endfor
	cd ${WRKSRC}/doc && make install-info
	if [ ! -f ${PREFIX}/info/dir ]; then \
		${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
.for info in xconq xcdesign
	install-info ${PREFIX}/info/${info}.info ${PREFIX}/info/dir
.endfor

.include <bsd.port.mk>
