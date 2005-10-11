# ex:ts=8
# Ports collection makefile for:	ctrlproxy
# Date created:			Oct 22, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ctrlproxy
PORTVERSION=	2.6.2
CATEGORIES=	irc
MASTER_SITES=	http://jelmer.vernstok.nl/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flexible IRC proxy

LIB_DEPENDS=	tdb.1:${PORTSDIR}/databases/tdb \
		pcre.0:${PORTSDIR}/devel/pcre \
		popt.0:${PORTSDIR}/devel/popt

USE_OPENSSL=	yes
USE_GNOME=	glib20 libxml2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
PORTDOCS1=	AUTHORS ChangeLog README TODO

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.if defined(WITH_CTRLPROXY_DOC)
BUILD_DEPENDS+=	xmlto:${PORTSDIR}/textproc/xmlto
BUILD_DEPENDS+=	dia:${PORTSDIR}/graphics/dia
CONFIGURE_ARGS+=	--enable-docs
MAN1=		ctrlproxy.1
MAN5=		ctrlproxyrc.5
MAN7=		admin.7ctrlproxy antiflood.7ctrlproxy \
		auto-away.7ctrlproxy ctcp.7ctrlproxy \
		linestack_file.7ctrlproxy linestack_memory.7ctrlproxy \
		log_custom.7ctrlproxy log_irssi.7ctrlproxy \
		motd-file.7ctrlproxy nickserv.7ctrlproxy \
		noticelog.7ctrlproxy repl_command.7ctrlproxy \
		repl_highlight.7ctrlproxy repl_none.7ctrlproxy \
		repl_simple.7ctrlproxy socket.7ctrlproxy \
		stats.7ctrlproxy strip.7ctrlproxy
PORTDOCS2=	ctrlproxy.html overview.png overview2.png
.endif

PORTDOCS=	${PORTDOCS1} ${PORTDOCS2}

post-install:
.if !defined(NOPORTDOC)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS1}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif
.if defined(WITH_CTRLPROXY_DOC)
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/doc/${i} ${PREFIX}/man/man1/
.endfor
.for i in ${MAN5}
	${INSTALL_MAN} ${WRKSRC}/doc/${i} ${PREFIX}/man/man5/
.endfor
.for i in ${MAN7}
	${INSTALL_MAN} ${WRKSRC}/doc/${i} ${PREFIX}/man/man7/
.endfor
.if !defined(NOPORTDOC)
.for i in ${PORTDOCS2}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}/
.endfor
.endif
.endif

.include <bsd.port.mk>
