# New ports collection makefile for:	lftp
# Date created:				11 September 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	lftp
PORTVERSION=	2.4.7
CATEGORIES=	ftp ipv6
MASTER_SITES=	ftp://ftp.yars.free.net/pub/software/unix/net/ftp/client/lftp/ \
		ftp://ftp.yars.free.net/pub/software/unix/net/ftp/client/lftp/old/ \
		ftp://ftp.phear.org/pub/linux/networking/ftp/client/lftp/ \
		ftp://ftp.phear.org/pub/linux/networking/ftp/client/lftp/old/ \
		http://the.wiretapped.net/mirrors/lftp/ \
		http://the.wiretapped.net/mirrors/lftp/old \
		ftp://ftp.wiretapped.net/pub/mirrors/lftp/ \
		ftp://ftp.wiretapped.net/pub/mirrors/lftp/old \
		ftp://ftp.ayamura.org/pub/lftp/ \
		ftp://ftp.ayamura.org/pub/lftp/old/

MAINTAINER=	fm@astral.ntu-kpi.kiev.ua

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

USE_BZIP2=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		lftp.1

post-install:
	@${INSTALL_DATA} ${WRKSRC}/lftp.conf ${PREFIX}/etc/lftp.conf.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in COPYING FAQ NEWS README THANKS TODO
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
