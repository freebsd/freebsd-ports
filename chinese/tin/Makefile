# New ports collection makefile for:	tin
# Version required:	tin1.4-971123
# Date created:		2 Dec 1997
# Whom:			Yen-Shuo Su <yssu@CCCA.NCTU.edu.tw>
#
# $Id: Makefile,v 1.1.1.1 1997/12/01 21:16:50 vanilla Exp $
#

DISTNAME=       tinpre-1.4-971123
PKGNAME=        zh-tin-1.4.971123
CATEGORIES=	chinese news
MASTER_SITES=   ftp://nuxi.ucdavis.edu/pub/tin/ \
		ftp://ftp.akk.uni-karlsruhe.de/pub/tin/ \
		ftp://ftp.nuxi.com/pub/tin/
EXTRACT_SUFX=	.tgz

MAINTAINER=     yssu@CCCA.NCTU.edu.tw

WRKSRC=         ${WRKDIR}/${DISTNAME:S/pre-1.4//}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=  --with-nntp-default-server=news  \
		 --with-spooldir=/var/news  \
		 --with-libdir=${PREFIX}/news/lib \
		 --with-mime-default-charset=ISO-8859-1 \
		 --enable-forgery \
		 --enable-break-long-lines \
		 --with-pgp=${PREFIX}/bin/pgp \
		 --with-ispell=${PREFIX}/bin/ispell \
		 --with-metamail=${PREFIX}/bin/metamail
MAKEFILE=	makefile
ALL_TARGET=     build
MAN1=		tin.1

.if defined(NNTP_ONLY)
CONFIGURE_ARGS+=	--enable-nntp-only
.endif

post-configure:
	${ECHO} '#define NNTP_SERVER_FILE "${PREFIX}/etc/nntpserver"' >>${WRKSRC}/include/autoconf.h
	${ECHO} '#define SMTP_SERVER_FILE "${PREFIX}/etc/smtpserver"' >>${WRKSRC}/include/autoconf.h

.include <bsd.port.mk>
