# New ports collection makefile for:	bftpd
# Date created:				7 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	bftpd
PORTVERSION=	1.0.24
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	http://bftpd.sourceforge.net/downloads/src/

MAINTAINER=	petef@FreeBSD.org
COMMENT=	Very configurable FTP server that can do chroot easily

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-pam
USE_GMAKE=	yes
USE_REINPLACE=	yes

MAN8=		bftpd.8

post-patch:
	@${REINPLACE_CMD} -e "s@chmod 644 /var@#chmod 644 /var@g; \
			s@touch /var@#touch /var@g; \
			s@DESTDIR)/etc@prefix)/etc@g; \
			s@bftpd.conf @bftpd.conf.sample @g" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's,/etc/bftpd.conf,${PREFIX}/etc/bftpd.conf,' \
		${WRKSRC}/mypaths.h
	@${REINPLACE_CMD} -e "s@-ldl@@" ${WRKSRC}/configure
	@${CP} ${WRKSRC}/bftpd.conf ${WRKSRC}/bftpd.conf.sample

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/en/bftpddoc-en.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/en/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
