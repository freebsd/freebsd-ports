# ex:ts=8
# New ports collection makefile for:    ncftp2
# Version required:     3.0
# Date created:         4 Nov 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.62 1998/12/08 20:25:18 obrien Exp $
#

DISTNAME=	ncftp-3.0beta17-src
PKGNAME=	ncftp-3.0b17
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ncftp.com/ncftp/3.0BETA/

MAINTAINER=	obrien@FreeBSD.ORG

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ncurses
MAN1=		ncftp3.1 ncftpbatch.1 ncftpget.1 ncftpls.1 ncftpput.1
MAN3=		Strn.3
NO_LATEST_LINK=	yes

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
LIBNCFTP= libncftp.so.2
LIBSTRN=libStrn.so.1
.else
LIBNCFTP= libncftp.so.2.0
LIBSTRN=libStrn.so.1.0
.endif

post-patch:
	@${MV} ${WRKSRC}/ncftp/pref.h ${WRKSRC}/ncftp/pref.h.in
	@${SED} -e 's:/etc/ncftp.firewall:${PREFIX}/etc/ncftp.firewall:' \
		${WRKSRC}/ncftp/pref.h.in > ${WRKSRC}/ncftp/pref.h

pre-build:
	cd ${WRKSRC}/Strn ; make so
	cd ${WRKSRC}/libncftp ; make so

do-install:
	@$(INSTALL_PROGRAM) $(WRKSRC)/bin/ncftp $(PREFIX)/bin/ncftp3
	@cd ${WRKSRC}/bin ; $(INSTALL_PROGRAM) \
		ncftpbatch ncftpget ncftpls ncftpput ncftpbookmarks \
		$(PREFIX)/bin
	@$(INSTALL_DATA) $(WRKSRC)/Strn/libStrn.so.1 $(PREFIX)/lib/$(LIBSTRN)
	@cd $(PREFIX)/lib && ${LN} -sf $(LIBSTRN) libStrn.so
	@$(INSTALL_DATA) $(WRKSRC)/libncftp/libncftp.so.2 $(PREFIX)/lib/$(LIBNCFTP)
	@cd $(PREFIX)/lib && ${LN} -sf $(LIBNCFTP) libncftp.so
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	@$(INSTALL_MAN) $(WRKSRC)/doc/man/ncftp.1 $(PREFIX)/man/man1/ncftp3.1
	@cd ${WRKSRC}/doc/man ; $(INSTALL_MAN) \
		ncftpbatch.1 ncftpget.1 ncftpls.1 ncftpput.1 \
		$(PREFIX)/man/man1
	@$(INSTALL_MAN) $(WRKSRC)/Strn/Strn.3 $(PREFIX)/man/man3

.include <bsd.port.post.mk>
