# New ports collection makefile for:	GNU emacs
# Version required:	19.34b
# Date created:		29 October 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.26 1996/11/19 13:14:40 asami Exp $
#

DISTNAME=	emacs-19.34b
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU}

WRKSRC=		${WRKDIR}/emacs-19.34
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	i386--freebsd --with-x-toolkit
STRIP=
MAN1=		emacs.1 etags.1 ctags.1

post-install:
	for file in emacs-19.34 emacsclient etags ctags b2m; do \
	  strip ${PREFIX}/bin/$$file; \
	done
	if [ ! -f ${PREFIX}/info/dir ]; then \
	  sed -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
	install-info ${PREFIX}/info/emacs ${PREFIX}/info/dir

.include <bsd.port.mk>
