#-*- mode: Fundamental; tab-width: 4; -*-
# ex:ts=4
#
# bsd.port.options.mk - Allow OPTIONS to determine dependencies
#
# usage:
#
#	.include "bsd.port.options.mk"
#	<deal with user options>
#	.include "bsd.port.pre.mk"
#	<other work, including adjusting dependencies>
#	.include "bsd.port.post.mk"
#
# Created by: Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$
#

OPTIONS_Include_MAINTAINER=		portmgr@FreeBSD.org

USEOPTIONSMK=	yes
INOPTIONSMK=	yes

.include "bsd.port.mk"

.undef INOPTIONSMK
