# New ports collection makefile for:	chimera + kanji patch
# Version required:	1.65
# Date created:		26 December 1994
# Whom:			asami
#
# $Id: Makefile,v 1.9 1995/05/27 04:48:30 asami Exp $
#

DISTNAME=	chimera-1.65
PKGNAME=	jp-chimera-1.65
CATEGORIES+=	japanese networking
MASTER_SITES=	ftp://ftp.cs.unlv.edu/pub/chimera/

PATCH_SITES=	ftp://ftp.tohoku.ac.jp/pub/net/www/chimera/
PATCHFILES=	chimera-1.65-kanji.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	asami@FreeBSD.ORG

USE_IMAKE=	yes
IS_INTERACTIVE=	yes

pre-install:
	@echo "**************************************************************"
	@echo "*                      W a r n i n g                         *"
	@echo "* This port will overwrite an existing chimera installation. *"
	@echo "**************************************************************"
	@echo -n "Is this ok? (y/n) ==> "
	@(read ans; \
	  case x"$$ans" in \
	    xy*|xY*) \
		return 0; \
		;; \
	    *) \
		echo "Okay, I won't install it then...."; \
		echo "(Don't worry about the following \"*** Error code 1\"s)"; \
		return 1; \
		;; \
	  esac)

.include <bsd.port.mk>
