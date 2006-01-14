# New ports collection makefile for:	Mono and it's consumers
# Date created:				15 October 2005
# Whom:					Tom McLaughlin <tmclaugh@FreeBSD.org>
#
# bsd.mono.mk: accomodate the peculiarities of building C# ports within
# the FreeBSD ports system.
#
# $FreeBSD$
#   $Id: bsd.mono.mk,v 1.7 2005/11/15 03:09:57 tmclau02 Exp $
#

# Set the location of the .wapi directory so we write to a location we
# can always assume to be writable.
MONO_SHARED_DIR=${WRKDIR}
CONFIGURE_ENV+=MONO_SHARED_DIR="${MONO_SHARED_DIR}"
MAKE_ENV+=MONO_SHARED_DIR="${MONO_SHARED_DIR}"


# Clean up the semaphore produced by the .wapi
post-install: mono-semdel
pre-clean: mono-semdel

mono-semdel:
	@${SETENV} MONO_SHARED_DIR="${MONO_SHARED_DIR}" ${LOCALBASE}/bin/mono-semdel 2> /dev/null || true
