# New ports collection makefile for:	mh (Japanese)
# Version required:	6.8.3-JP.2c
# Date created:		28 March 1995
# Whom:			Akito FUJITA <fujita@zoo.ncl.omron.co.jp>
#
# $Id:$
#

DISTNAME=	mh-6.8.3
PKGNAME=	jp-mh-6.8.3
MASTER_SITES=	ftp://omrongw.wg.omron.co.jp/pub/net/mail/
DISTFILES=	mh-6.8.3-JP.2c.tar.gz

MAINTAINER=	asami@FreeBSD.ORG

IS_INTERACTIVE=	yes

pre-install:
	@echo "***********************************************************"
	@echo "*                      W a r n i n g                      *"
	@echo "* This port will overwrite the mh installation on your    *"
	@echo "*  system if you already have the original one.           *"
	@echo "***********************************************************"
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
