# New ports collection makefile for:	GNU emacs
# Version required:	19.34b
# Date created:		29 October 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.30 1997/12/14 02:03:53 asami Exp $
#

DISTNAME=	emacs-19.34b
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	ports@FreeBSD.ORG

NO_LATEST_LINK=	yes
WRKSRC=		${WRKDIR}/emacs-19.34
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	i386--freebsd --with-x-toolkit
STRIP=
MAN1=		emacs.1 etags.1 ctags.1

post-install:
.for file in emacs-19.34 emacsclient etags ctags b2m
	strip ${PREFIX}/bin/${file}
.endfor
	if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
.for info in emacs vip viper forms gnus mh-e cl sc dired-x ediff ccmode message
	install-info ${PREFIX}/info/${info} ${PREFIX}/info/dir
.endfor

.include <bsd.port.mk>
