# Ports collection makefile for:  wget+ipv6
# Date created:			  17 Dec 2001
# Whom:				  FUJISHIMA Satsuki <sf@FreeBSD.org>
#
# $FreeBSD$
#

# ftp/wget has now IPv6 capability. This port will be retired in near future.

PORTNAME=	wget
PORTVERSION=	1.7
PORTREVISION=	4
CATEGORIES=	ftp www ipv6
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.dl.ac.uk/ccp14/ftp-mirror/wget/pub/unix/util/wget/ \
		ftp://ftp.informatik.hu-berlin.de/gnu/wget/ \
		ftp://ftp.uni-mainz.de/pub/gnu/wget/ \
		ftp://ftp.max.irk.ru/unix/net/www/wget/
MASTER_SITE_SUBDIR=	wget
PKGNAMESUFFIX=	+ipv6

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/kame/misc/&,}
PATCHFILES=	wget-17-v6-20010716a.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	sf@FreeBSD.org
COMMENT=	Retrieve files from the Net via HTTP and FTP with IPv6 capability

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old

.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS=	--with-ssl=${OPENSSLBASE}
.endif
USE_PERL5_BUILD=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
MAKE_ENV=	OLD_PO_FILE_INPUT=1

MAN1=		wget.1

post-patch:
# made by broken KAME patch. Already contacted.
	@${RM} -f ${WRKSRC}/po/zh.po*
# we don't need to run autoconf.
	${TOUCH} ${WRKSRC}/configure
# convert utf-8 to Big5 for FreeBSD's default old fashioned gettext.
	(cd ${WRKSRC}; \
	${MV} po/zh_TW.po po/zh_TW.po.utf-8; \
	${LOCALBASE}/bin/iconv -f UTF-8 -t BIG5 po/zh_TW.po.utf-8 |\
		${SED} -e 's,utf-8,big5,' |\
		${ENV} LANG=C ${SED} -Ee 's,([^[:print:]])\\,\1\\\\,g' |\
		${SED} -Ee 's,\\\\([nt"]),\\\1,g' \
		    > po/zh_TW.po)

pre-build:
	@${RM} -f ${WRKSRC}/doc/wget.info*

post-install:
	install-info ${PREFIX}/info/wget.info ${PREFIX}/info/dir

.include <bsd.port.mk>
