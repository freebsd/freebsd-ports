// from https://faustdoc.grame.fr/tutorials/basic-osc/

import("stdfaust.lib");
f = hslider("freq",440,50,2000,0.01);
g = hslider("gain",1,0,1,0.01);
t = si.smoo(button("gate"));
phasor(freq) = (+(freq/ma.SR) ~ ma.frac);
osc(freq) = sin(phasor(freq)*2*ma.PI);
organ(freq) = (osc(freq) + osc(freq*2) + osc(freq*3))/3;
process = organ(f)*g*t;
