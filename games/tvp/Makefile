# New ports collection makefile for:	tvp
# Version Required:	0.9.7.1
# Date Created:		3 Jul 1996
# Whom:			Tim Vanderhoek <ac199@hwcn.org>
#
# $Id: Makefile,v 1.4 1998/07/15 16:00:52 hoek Exp $
#

DISTNAME=	tvp-0.9.7.1
CATEGORIES=	games tk80
MASTER_SITES=	http://www3.sympatico.ca/john.vanderhoek/tim/src/president/

MAINTAINER=	hoek@FreeBSD.ORG

# If you comment this out, the port should automatically use whichever
# version of tk you have installed, or, lacking all versions, it will
# build only the ANSI and terminal interfaces (not the nice X interface).
LIB_DEPENDS=	tk80\\.1\\.:${PORTSDIR}/x11-toolkits/tk80

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-tcl-dir=${PREFIX}/lib \
			--enable-carddir=${PREFIX}/share/games/tvp

MAN6=	tvp.6

DOCFILES=	aprez.txt libass.txt president.txt prez.txt xprez.txt

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tvp
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${PREFIX}/share/doc/tvp
.endfor
.endif
	${INSTALL_MAN} ${FILESDIR}/tvp.6 ${PREFIX}/man/man6/tvp.6
	a='${PREFIX}/share/doc/tvp/' perl -pi -e 's/TOKEN/$$ENV{a}/' \
		${PREFIX}/man/man6/tvp.6
	strip ${PREFIX}/bin/xpwish ${PREFIX}/bin/aprez ${PREFIX}/bin/prez

.include <bsd.port.mk>
