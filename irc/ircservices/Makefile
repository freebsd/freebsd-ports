# Created by: Alex Dupre <sysadmin@alexdupre.com>
# $FreeBSD$

PORTNAME=	ircservices
PORTVERSION=	5.1.18
PORTREVISION=	7
CATEGORIES=	irc
MASTER_SITES=	http://www.ircservices.za.net/download/ \
		http://banana.irc.gr/ircservices/ \
		ftp://ftp.freenet.de/pub/ftp.ircservices.za.net/pub/ircservices/

MAINTAINER=	rum1cro@yandex.ru
COMMENT=	System of IRC services for IRC networks

BROKEN=		unfetchable

LICENSE=	GPLv2

USES=		gmake perl5
USE_GCC=	any
USE_PERL5=	build
HAS_CONFIGURE=	yes
USE_RC_SUBR=	ircservices
SUB_FILES=	pkg-message

DIST_SUBDIR=	${PORTNAME}
CONFIGURE_ARGS=	-bindest ${PREFIX}/sbin -datdest ${PREFIX}/etc/ircservices \
				-cflags "${CFLAGS}" -cc "${CC}"
MAKE_JOBS_UNSAFE=	yes

IRCSERVICES_LANG?=	EN_US

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

pre-patch:
	@${ECHO_MSG} "You can set IRCSERVICES_LANG to the following language"
	@${ECHO_MSG} "codes to select language the services will use when"
	@${ECHO_MSG} "communicating with users:"
	@${ECHO_MSG} "(Be aware of the capitalization!)"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "DE EN_US ES FR HU IT JA_EUC JA_SJIS NL PT TR"

post-patch:
	@${REINPLACE_CMD} -e 's#LANG_EN_US#LANG_${IRCSERVICES_LANG}#' \
		${WRKSRC}/defs.h

post-build:
	@${REINPLACE_CMD} -e 's#BINDEST=.*#BINDEST=${STAGEDIR}${PREFIX}/sbin# ; \
		s#DATDEST=.*#DATDEST=${STAGEDIR}${PREFIX}/etc/ircservices#' \
			${WRKSRC}/Makefile.inc
	@${REINPLACE_CMD} -e 's#@BINDEST@#${PREFIX}/sbin# ; \
		s#@DATDEST@#${PREFIX}/etc/ircservices#' \
			${WRKSRC}/tools/ircservices-chk.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})

.include <bsd.port.post.mk>
