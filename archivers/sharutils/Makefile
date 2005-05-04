# New ports collection makefile for:	gshar+gunshar
# Date created:		28 Dec 1994
# Whom:			ache
#
# $FreeBSD$
#

PORTNAME=	sharutils
PORTVERSION=	4.3.80
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}/REL-${PORTVERSION}

MAINTAINER=	sylvioc@gmail.com
COMMENT=	Pack, send and unpack shell archives; synchronize via e-mail

USE_PERL5=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g --disable-uucode
INSTALL_TARGET=	install install-man
MAN1=		gshar.1 gunshar.1
INFO=		sharutils
PLIST_FILES=	bin/gmail-files bin/gmailshar bin/gremsync bin/gshar bin/gunshar

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
.else
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--with-libintl-prefix="${LOCALBASE}"
.for l in et it vi fi sr rw ca cs da de el es fr gl hu ja nb nl nn pt ru sv tr zh_TW
PLIST_FILES+=	share/locale/${l}/LC_MESSAGES/sharutils.mo
.endfor
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|@SH@|${SH}|' \
		${WRKSRC}/src/mail-files.in ${WRKSRC}/src/mailshar.in
	@${REINPLACE_CMD} -e 's|@PERL@|${PERL}|' ${WRKSRC}/src/remsync.in
	@${FIND} ${WRKSRC} -name \*.c  -or -name \*.h | ${XARGS} \
		${REINPLACE_CMD} -e 's|uintmax_t|unsigned long long|;s|intmax_t|long long|'

.include <bsd.port.mk>
