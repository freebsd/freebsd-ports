# ex:ts=8
# Ports collection makefile for:  ncftp3
# Date created:			  4 Nov 1994
# Whom:				  ache
#
# $FreeBSD$
#

PORTNAME=	ncftp3
PORTVERSION=	3.0.2
PORTREVISION=	1
CATEGORIES=	ftp ipv6
MASTER_SITES=	ftp://ftp.ncftp.com/ncftp/
DISTNAME=	ncftp-${PORTVERSION}-src

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	ncftp-302-v6-20010302.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	obrien@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ncurses
MAN1=		ncftp3.1 ncftpbatch.1 ncftpget.1 ncftpls.1 ncftpput.1
MAN3=		Strn.3

LIBNCFTP=	libncftp.so.2
LIBSTRN=	libStrn.so.1

post-patch:
	@${MV} ${WRKSRC}/ncftp/pref.h ${WRKSRC}/ncftp/pref.h.in
	@${SED} -e 's:/etc/ncftp.firewall:${PREFIX}/etc/ncftp.firewall:' \
		${WRKSRC}/ncftp/pref.h.in > ${WRKSRC}/ncftp/pref.h

pre-build:
	cd ${WRKSRC}/Strn ; make so
	cd ${WRKSRC}/libncftp ; make so

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/ncftp ${PREFIX}/bin/ncftp3
	@cd ${WRKSRC}/bin ; ${INSTALL_PROGRAM} \
		ncftpbatch ncftpget ncftpls ncftpput ncftpbookmarks \
		${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/Strn/libStrn.so.1 ${PREFIX}/lib/${LIBSTRN}
	@cd ${PREFIX}/lib && ${LN} -sf ${LIBSTRN} libStrn.so
	@${INSTALL_DATA} ${WRKSRC}/libncftp/libncftp.so.2 ${PREFIX}/lib/${LIBNCFTP}
	@cd ${PREFIX}/lib && ${LN} -sf ${LIBNCFTP} libncftp.so
	@${INSTALL_MAN} ${WRKSRC}/doc/man/ncftp.1 ${PREFIX}/man/man1/ncftp3.1
	@cd ${WRKSRC}/doc/man ; ${INSTALL_MAN} \
		ncftpbatch.1 ncftpget.1 ncftpls.1 ncftpput.1 \
		${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/Strn/Strn.3 ${PREFIX}/man/man3

.include <bsd.port.mk>
