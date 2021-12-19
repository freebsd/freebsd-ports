/**
 * @file
 *
 * @author jeffrey.daily@gmail.com
 *
 * Copyright (c) 2015 Battelle Memorial Institute.
 *
 * For non-intel platforms, stub out the intel feature tests.
 */
#include "config.h"

#include "parasail/cpuid.h"

int parasail_can_use_avx512vbmi()
{
    return 0;
}

int parasail_can_use_avx512bw()
{
    return 0;
}

int parasail_can_use_avx512f()
{
    return 0;
}

int parasail_can_use_avx2()
{
    return 0;
}

int parasail_can_use_sse41()
{
    return 0;
}

int parasail_can_use_sse2()
{
    return 0;
}

int parasail_can_use_altivec()
{
#if HAVE_ALTIVEC
    return 1;
#else
    return 0;
#endif
}

int parasail_can_use_neon()
{
    return 0;
}

