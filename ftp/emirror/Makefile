# ex:ts=8
# New ports collection makefile for:	emirror
# Date created:			Apr 19, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	emirror
PORTVERSION=	2.2.0.0.4
PORTREVISION=	0
CATEGORIES=	ftp python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://eclipt.uni-klu.ac.at/pub/projects/emirror/snapshots/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-2.2.0-0.4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A full features FTP-mirroring software with nice logfiles

HTMLDIR?=	${PREFIX}/www/emirror
LOCKDIR?=	/tmp/emirror-locks

USE_REINPLACE=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-htmldir=${HTMLDIR}
USE_GMAKE=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/emirror bin/mirror bin/updateindex
MAN1=	emirror.1

post-patch:
	@${REINPLACE_CMD} -e "s| -b | |" \
		-e "s|[$$][(]prefix[)]/var/emirror/locks|${LOCKDIR}|" \
		${WRKSRC}/Makefile.in
.for file in cgi/status.cgi.in etc/general.cfg.in
	@${REINPLACE_CMD} -e "s|@prefix@/var/emirror/locks|${LOCKDIR}|" \
		${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -e "s|/var/tmp/emirror-locks/|${LOCKDIR}|" \
		${WRKSRC}/main.py
	@${GREP} -lR "/var/www" ${WRKSRC}/etc | ${XARGS} \
		${REINPLACE_CMD} -e "s,/var/www,${HTMLDIR},"

post-install:
	@${FIND} ${PREFIX}/lib/emirror -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm lib/emirror" >> ${TMPPLIST}
	@${FIND} ${PREFIX}/etc/emirror -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${PREFIX}/etc/emirror -type d | ${SORT} -r | \
		${SED} "s,^${PREFIX}/,@dirrm ," >> ${TMPPLIST}
	@${FIND} ${HTMLDIR} -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm ${HTMLDIR:S,^${PREFIX}/,,}" >> ${TMPPLIST}

.include <bsd.port.mk>
