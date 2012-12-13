# Created by: Chip Marshall <chip@eboai.org>
# $FreeBSD$

PORTNAME=	icecast
PORTVERSION=	1.3.12
PORTREVISION=	2
CATEGORIES=	audio net
MASTER_SITES=	http://downloads.xiph.org/releases/icecast/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A streaming mp3 audio server

LICENSE=	GPLv2 # (or later)

OPTIONS_DEFINE=	DOCS

USE_READLINE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libwrap
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

pre-patch:
	@${REINPLACE_CMD} -e \
		's|<readline.h>|<readline/readline.h>| ; \
		 s|<history.h>|<readline/history.h>|' ${WRKSRC}/src/admin.c
	@${REINPLACE_CMD} -e \
		's|HAVE_HISTORY_H|HAVE_READLINE_HISTORY_H|g' ${WRKSRC}/config.h.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/icecast ${PREFIX}/sbin
	@${MKDIR} ${ETCDIR}/conf
.for CONF in groups.aut.dist icecast.conf.dist mounts.aut.dist users.aut.dist
	${INSTALL_DATA} ${WRKSRC}/conf/${CONF} ${ETCDIR}/conf
.endfor
	@${MKDIR} ${ETCDIR}/templates
.for TEMPL in 306.html 400.html 403.html 404.html 504.html bodytag.html \
	info.html list_directory.html mountlist.html statistics.html \
	admin_describe.html admin.html alias_add.html manual.html \
	alias_del.html header.html footer.html admin_change.html
	${INSTALL_DATA} ${WRKSRC}/templates/${TEMPL} ${ETCDIR}/templates
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/manual.html ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
