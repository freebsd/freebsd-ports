# New ports collection makefile for:	bftpd
# Date created:				7 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	bftpd
PORTVERSION=	1.0.21
CATEGORIES=	ftp
MASTER_SITES=	http://www.bftpd.f2s.com/downloads/src/

MAINTAINER=	petef@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-pam

MAN8=		bftpd.8

post-patch:
	@${PERL} -pi -e "s@<wait.h>@<sys/wait.h>@g" ${WRKSRC}/commands.c
	@${PERL} -pi -e "s@chmod 644 /var@#chmod 644 /var@g; \
			s@touch /var@#touch /var@g; \
			s@DESTDIR\)/etc@prefix\)/etc@g; \
			s@bftpd.conf @bftpd.conf.sample @g" ${WRKSRC}/Makefile.in
	@${PERL} -pi -e "s@-ldl@@" ${WRKSRC}/configure
	@${CP} ${WRKSRC}/bftpd.conf ${WRKSRC}/bftpd.conf.sample

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/bftpd
	${INSTALL_DATA} ${WRKSRC}/doc/bftpddoc.txt ${PREFIX}/share/doc/bftpd
.endif

.include <bsd.port.mk>
