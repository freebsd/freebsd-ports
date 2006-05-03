# New ports collection makefile for:	gshar+gunshar
# Date created:		28 Dec 1994
# Whom:			ache
#
# $FreeBSD$
#

PORTNAME=	sharutils
PORTVERSION=	4.3.81
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}/REL-${PORTVERSION}

MAINTAINER=	sylvioc@gmail.com
COMMENT=	Pack, send and unpack shell archives; synchronize via e-mail

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g --disable-uucode
INSTALL_TARGET=	install install-man
MAN1=		gshar.1 gunshar.1
INFO=		sharutils

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=--disable-nls
.else
PLIST_SUB+=	NLS=""
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--with-libintl-prefix="${LOCALBASE}"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|@SH@|${SH}|' \
		${WRKSRC}/src/mail-files.in ${WRKSRC}/src/mailshar.in
	@${REINPLACE_CMD} -e 's|@PERL@|${PERL}|' ${WRKSRC}/src/remsync.in
	@${FIND} ${WRKSRC} -name \*.c  -or -name \*.h | ${XARGS} \
		${REINPLACE_CMD} -e 's|uintmax_t|unsigned long long|;s|intmax_t|long long|'

.include <bsd.port.mk>
