# New ports collection makefile for:	libidn
# Date created:        	19.06.2003
# Whom:               	Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	libidn
PORTVERSION=	0.3.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU_ALPHA} \
		http://josefsson.org/libidn/releases/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Internationalized Domain Names command line tool

LIB_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv
BUILD_DEPENDS=	gengetopt:${PORTSDIR}/devel/gengetopt

USE_PERL5_BUILD=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes
USE_GETOPT_LONG=	yes
USE_GNOME=	gnomehack
INFO=		libidn
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.if exists(${LOCALBASE}/bin/emacs)
PLIST_SUB+=	EMACS="" EMACSDIR=share/emacs
.elif exists(${LOCALBASE}/bin/xemacs)
PLIST_SUB+=	EMACS="" EMACSDIR=lib/xemacs
.else
PLIST_SUB+=	EMACS="@comment " EMACSDIR=""
.endif

MAN1=	idn.1
MAN3=	idna_to_ascii_4i.3 idna_to_ascii_4z.3 idna_to_ascii_8z.3		\
	idna_to_ascii_lz.3 idna_to_unicode_44i.3 idna_to_unicode_4z4z.3		\
	idna_to_unicode_8z4z.3 idna_to_unicode_8z8z.3 idna_to_unicode_8zlz.3  	\
	idna_to_unicode_lzlz.3 punycode_decode.3 punycode_encode.3		\
	stringprep.3 stringprep_check_version.3 stringprep_convert.3		\
	stringprep_locale_charset.3 stringprep_locale_to_utf8.3			\
	stringprep_profile.3 stringprep_ucs4_nfkc_normalize.3 			\
	stringprep_ucs4_to_utf8.3 stringprep_unichar_to_utf8.3			\
	stringprep_utf8_nfkc_normalize.3 stringprep_utf8_to_locale.3		\
	stringprep_utf8_to_ucs4.3 stringprep_utf8_to_unichar.3			\
	stringprep_4i.3 stringprep_4zi.3

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README FAQ
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
