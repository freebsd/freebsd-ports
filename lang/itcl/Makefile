# New ports collection makefile for:	itcl
# Version required:	2.1
# Date created:		Aug 17 1996
# Whom:			chuckr
#
# $Id: Makefile,v 1.20 1997/07/17 15:12:47 max Exp $
#

DISTNAME=	itcl2.1
PKGNAME=	itcl-2.1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.neosoft.com/pub/tcl/sorted/devel/

MAINTAINER=	chuckr@freebsd.org

BROKEN=		"installation does not DTRT"
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --exec_prefix=${PREFIX}
USE_XLIB=	yes

post-extract:
	@$(RM) -f $(WRKSRC)/tcl7.5/library/*.c

post-install:
.if !defined(NOMANCOMPRESS)
	@$(ECHO) "Compressing man pages, be patient, there are many."
	@for m in $(WRKSRC)/tcl7.5/doc/*.1 ;\
	do gzip -9nf $(PREFIX)/share/itcl/tcl7.5/man/man1/`$(BASENAME) $$m`;done
	@for m in $(WRKSRC)/tcl7.5/doc/*.3 ;\
	do gzip -9nf $(PREFIX)/share/itcl/tcl7.5/man/man3/`$(BASENAME) $$m`;done
	@for m in $(WRKSRC)/tcl7.5/doc/*.n ;\
	do gzip -9nf $(PREFIX)/share/itcl/tcl7.5/man/mann/`$(BASENAME) $$m`;done
	@for m in $(WRKSRC)/tk4.1/doc/*.1 ;\
	do gzip -9nf $(PREFIX)/share/itcl/tk4.1/man/man1/`$(BASENAME) $$m`;done
	@for m in $(WRKSRC)/tk4.1/doc/*.3 ;\
	do gzip -9nf $(PREFIX)/share/itcl/tk4.1/man/man3/`$(BASENAME) $$m`;done
	@for m in $(WRKSRC)/tk4.1/doc/*.n ;\
	do gzip -9nf $(PREFIX)/share/itcl/tk4.1/man/mann/`$(BASENAME) $$m`;done
	@for m in $(WRKSRC)/itcl/doc/*.1 ;\
	do gzip -9nf $(PREFIX)/share/itcl/itcl/man/man1/`$(BASENAME) $$m`;done
	@for m in $(WRKSRC)/itcl/doc/*.n ;\
	do gzip -9nf $(PREFIX)/share/itcl/itcl/man/mann/`$(BASENAME) $$m`;done
	@for m in $(WRKSRC)/itk/doc/*.1 ;\
	do gzip -9nf $(PREFIX)/share/itcl/itk/man/man1/`$(BASENAME) $$m`;done
	@for m in $(WRKSRC)/itk/doc/*.n ;\
	do gzip -9nf $(PREFIX)/share/itcl/itk/man/mann/`$(BASENAME) $$m`;done
	@for m in $(WRKSRC)/iwidgets2.1.0/doc/*.n ; \
	do gzip -9nf $(PREFIX)/share/itcl/iwidgets/man/mann/`$(BASENAME) $$m`;done
.endif
	@echo "*****************************************************"
	@echo "There are new man directories to install now:"
	@echo "Add $(PREFIX)share/itcl/tcl7.5"
	@echo "                         tk4.1"
	@echo "                         itcl"
	@echo "                         itk"
	@echo "                         iwidgets"
	@echo "To the manpath in /etc/manpath.config"
	@echo "*****************************************************"
	${LDCONFIG} -m $(PREFIX)/lib

.include <bsd.port.mk>
