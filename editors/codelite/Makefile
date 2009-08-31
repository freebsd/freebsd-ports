# New ports collection makefile for: 	codelite
# Date created:				7 May 2008
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	codelite
DISTVERSION=	1.0.${SVN_REVISION}
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/Releases/${PORTNAME}-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	An Open Source IDE for C/C++

LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl

OPTIONS=	CSCOPE	"Enable CScope integration" OFF

USE_WX=		2.8
WX_UNICODE=	yes
USE_GNOME=	gtk20
USE_GMAKE=	yes
HAS_CONFIGURE=	yes

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386 amd64 sparc64

SVN_REVISION=	2893

.if defined(WITH_CSCOPE)
RUN_DEPENDS+=	cscope:${PORTSDIR}/devel/cscope
.endif

post-patch:
.if ${ARCH} == "amd64"
	${REINPLACE_CMD} -e '58s|=|= -fPIC|' ${WRKSRC}/configure
.endif
	${REINPLACE_CMD} -e 's|wx-config|${WX_CONFIG}|g' ${WRKSRC}/configure
#	Configure script does not respect --prefix
	${REINPLACE_CMD} -e '/^prefix/s|/usr|${PREFIX}|; \
	    /^plugins_dir/s|/usr/lib/codelite|${DATADIR}/plugins|' \
	    ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|$${cur_rev}|${SVN_REVISION}|' \
	    ${WRKSRC}/le_makerevision.sh
# 	CTags already installed
	(if [ -f ${LOCALBASE}/include/readtags.h ]; then \
	    ${RM} ${WRKSRC}/CodeLite/readtags.h; \
	 fi; \
	)

.include <bsd.port.post.mk>
