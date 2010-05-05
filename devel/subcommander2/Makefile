# New ports collection makefile for:	subcommander2
# Date created:				6 August 2008
# Whom:					Naram Qashat
#
# $FreeBSD$
#

PORTNAME=	subcommander
PORTVERSION=	2.0.0.b5
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://subcommander.tigris.org/files/documents/1759/46766/
DISTNAME=	Subcommander-${PORTVERSION:S/.b/b/g}p1

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Qt4 based multiplatform subversion client, diff & merge tool

LIB_DEPENDS=	neon.29:${PORTSDIR}/www/neon29 \
		boost_thread.4:${PORTSDIR}/devel/boost-libs \
		svn_client-1.0:${PORTSDIR}/devel/subversion \
		sasl2.2:${PORTSDIR}/security/cyrus-sasl2

LATEST_LINK=	subcommander2
CONFLICTS=	subcommander-1.*

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.b/b/g}
USE_DOS2UNIX=	*.cpp

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qt3support gui network corelib moc_build uic_build rcc_build
CONFIGURE_ARGS+=	--with-boost=${LOCALBASE}/include --with-neon=${LOCALBASE} \
			--with-subversion=${LOCALBASE} --with-qt=${LOCALBASE} \
			--with-apr=${LOCALBASE}/bin/apr-1-config \
			--with-apr-util=${LOCALBASE}/bin/apu-1-config \
			--with-openssl=${OPENSSLBASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${LOCALBASE}/lib/qt4 ${PTHREAD_LIBS}"

post-extract:
	@${CHMOD} +x ${WRKSRC}/configure

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		Does not compile on 6.x
.endif

.include <bsd.port.post.mk>
