# Created by: Daichi GOTO <daichi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mozc-additions
PORTVERSION=	1.11.1502.102
CATEGORIES=	japanese
MASTER_SITES=	# empty
PKGNAMEPREFIX?=	ja-
DISTFILES=	# empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Additional tools and images for Mozc Japanese Input Method

NO_BUILD=	yes
PLIST_FILES=	bin/ibus-daemon_restart \
		bin/ibus-daemon_start \
		bin/ibus-daemon_stop \
		bin/mozc_server_restart \
		bin/mozc_server_start \
		bin/mozc_server_stop \
		bin/mozc_tool_character_palette \
		bin/mozc_tool_config \
		bin/mozc_tool_dictionary \
		bin/mozc_tool_hand_writing \
		bin/mozc_tool_word_register

do-install:
	${INSTALL_SCRIPT} ${PLIST_FILES:S,bin/,${FILESDIR}/,} ${PREFIX}/bin

.include <bsd.port.mk>
