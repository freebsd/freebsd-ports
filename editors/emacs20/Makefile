# New ports collection makefile for:	GNU emacs
# Version required:	20.2
# Date created:		29 October 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.30 1997/12/14 14:51:53 jseger Exp $
#

DISTNAME=	emacs-20.2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	jseger@FreeBSD.org

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	i386--freebsd --with-x-toolkit
STRIP=
MAN1=		emacs.1 etags.1 ctags.1

pre-build:
	${RM} -rf ${WRKSRC}/info/*
post-install:
	if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
.for info in ccmode cl dired-x ediff emacs forms gnus message mh-e \
     sc vip viper
	install-info ${PREFIX}/info/${info} ${PREFIX}/info/dir
.endfor

.include <bsd.port.mk>
