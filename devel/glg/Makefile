# New ports collection makefile for:	glg
# Date created:				23 May 2001
# Whom:					Olivier Singla <lo_gafet@users.sourceforge.net>
#
# $FreeBSD$
#

PORTNAME=	glg
PORTVERSION=	0.2.a
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_LOCAL}
#		http://glg.sourceforge.net/ \
#		${MASTER_SITE_SOURCEFORGE}
#MASTER_SITE_SUBDIR=	glg
MASTER_SITE_SUBDIR=	kris

MAINTAINER=	lo_gafet@users.sourceforge.net

USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
WANT_GNOME=	yes

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomelibs}!=""
USE_GNOME+=	gnomelibs
.endif

pre-build:
	find ${WRKSRC} -name Makefile | xargs ${PERL} \
		-pi -e "s@gtk-config@${GTK_CONFIG}@g"

.include <bsd.port.post.mk>
